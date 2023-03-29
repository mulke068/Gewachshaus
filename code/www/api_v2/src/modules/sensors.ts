import mongoose,{ Schema , Model , Document} from 'mongoose';

const sensorSchema = new mongoose.Schema({
  // Schema for the data
    // _id: { type: mongoose.Schema.Types.ObjectId,auto: true, unique: true, index: true},
    id: {type: Number/*,auto: true,unique: true,index: true*/},
    timestamp: {type: Date/*,auto: true,default: Date.now()*/},
    created_at: {type: Date/*,auto: true,default: Date.now()*/},
    devices: {
        esp32: [{
                connected: {
                    type: Boolean,
                    index: false
                }
            },
            {
                connected: {
                    type: Boolean,
                    index: false
                }
            }
        ],
        raspberrypi: {
            connected: {
                type: Boolean
            },
        }
    },
    tempHum: {
        temperature_1: {
            type: Number
        },
        humidity_1: {
            type: Number
        },
        temperature_2: {
            type: Number
        },
        humidity_2: {
            type: Number
        }
    },
    waterSystem: {
        sensor_1: {
            type: Number
        },
        sensor_2: {
            type: Number
        },
        pumpe: {
            type: Boolean
        }

    },
    lufterLeds: {
        getLufter_1: {
            type: Number
        },
        setLufter_1: {
            type: Boolean
        },
        getLufter_2: {
            type: Number
        },
        setLufter_2: {
            type: Boolean
        },
        getLed: {
            type: Number
        },
        setLed: {
            type: Boolean
        }
    },
    energieStatus: {
        solar_1: {
            type: Number
        },
        solar_2: {
            type: Number
        },
        akku: {
            type: Number
        },
        strom: {
            type: Number
        }
    },
    settings: {
        brightness: {
            type: Number
        },
        sound: {
            type: Number
        }
    }
});  

sensorSchema.pre('save', async function (next){
    try{
        var count = await mongoose.model('Sensor_Data').countDocuments();
        const doc = this;
        if (doc.isNew) {
            doc.id = count + 1;
            doc.timestamp = new Date();
            doc.created_at = new Date();
            return next();
        } else {
            doc.timestamp = new Date();
            return next();
        }
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            message: err.message || "Some error occurred while creating the data."
        });
    };
});

module.exports = mongoose.model('Sensor_Data', sensorSchema);