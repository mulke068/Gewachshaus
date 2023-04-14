/* eslint-disable @typescript-eslint/no-unsafe-call */
/* eslint-disable @typescript-eslint/no-unsafe-member-access */
/* eslint-disable @typescript-eslint/no-unsafe-assignment */
/* eslint-disable @typescript-eslint/no-this-alias */
/* eslint-disable @typescript-eslint/no-unsafe-return */
import { createRequire } from "module";
import mongoose, { Schema , Document } from "mongoose";

export interface HookNextFunction {
    // eslint-disable-next-line @typescript-eslint/no-explicit-any
    (error?: Error): any
}

export interface IDisplay_Data extends mongoose.Document{
    // _id: mongoose.Schema.Types.ObjectId;
    id: number;
    timestamp: Date;
    created_at: Date;
    devices: {
        esp32: [
            {
                connected: boolean;
            },
            {
                connected: boolean;
            }
        ];
        raspberrypi: {
            connected: boolean;
        };
    };
    tempHum: {
        temperature_1: number;
        humidity_1: number;
        temperature_2: number;
        humidity_2: number;
    };
    waterSystem: {
        sensor_1: number;
        sensor_2: number;
        pumpe: boolean;
    };
    lufterLeds: {
        getLufter_1: number;
        setLufter_1: boolean;
        getLufter_2: number;
        setLufter_2: boolean;
        getLed: number;
        setLed: boolean;
    };
    energieStatus: {
        solar_1: number;
        solar_2: number;
        akku: number;
        strom: number;
    };
    settings: {
        brightness: number;
        sound: number;
    };
}

const DisplaySchema = new mongoose.Schema({
    // Schema for the data
    // _id: { type: mongoose.Schema.Types.ObjectId,auto: true, unique: true, index: true},
    id: {type: Number/*,auto: true,unique: true,index: true*/},
    timestamp: {type: Date/*,auto: true,default: Date.now()*/},
    created_at: {type: Date/*,auto: true,default: Date.now()*/},
    devices: {
        esp32: [{
                connected: {
                    type: Boolean,
                    index: false,
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
//SensorSchema.static.build = (attrs: IDisplay_Data) => {
//    return new Display_Data(attrs);
//}

DisplaySchema.pre("save", async function (next: HookNextFunction) {
    try{
        const counter: number = await mongoose.model('Display_Data').countDocuments();
        const doc: any = this;
        if (doc.isNew) {
            doc.id = counter + 1;
            doc.timestamp = new Date();
            doc.created_at = new Date();
            return next();
        } else {
            doc.timestamp = new Date();
            return next();
        }
    } catch (err: any) {
        console.log(err);
        /*res.status(500).send({
            message: err.message || "Some error occurred while creating the data."
        });*/
    }
});

export const Display_Data = mongoose.model("Display_Data", DisplaySchema);

//export default Display_Data;
//module.exports = Display_Data;
//export { Display_Data}

/*
Display_Data.build({
    id: 1,
    timestamp: new Date(),
    created_at: new Date(),
    devices: {
        esp32: [{
            connected: true
        },
        {
            connected: false
        }
        ],
        raspberrypi: {
            connected: true
        }
    },
    tempHum: {
        temperature_1: 50,
        humidity_1: 40,
        temperature_2: 30,
        humidity_2: 40
    },
    waterSystem: {
        sensor_1: 54,
        sensor_2: 20,
        pumpe: false
    },
    lufterLeds: {
        getLufter_1: 50,
        setLufter_1: true,
        getLufter_2: 0,
        setLufter_2: false,
        getLed: 80,
        setLed: true
    },
    energieStatus: {
        solar_1: 7.5,
        solar_2: 7.2,
        akku: 90,
        strom: 7.8
    },
    settings: {
        brightness: 100,
        sound: 0
    }
});
*/