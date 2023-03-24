const express = require("express");
const http = require("http");
const cors = require("cors");
const bodyParser = require("body-parser");
const dotenv = require("dotenv");
const mongoose = require("mongoose");

require("dotenv").config( /*{ path: "../.env"}*/ );

const app = express();
const server = http.createServer(app);
const port = process.env.PORT || 8181;
const MONGO_URI = process.env.MONGO_URI || "mongodb://root:root@127.0.0.1:27017/?authMechanism=DEFAULT";

//
const Sensor_Data = require("../scr/modules/data.js");

// -------------------CORS-------------------------
app.use(cors({
    origin: true,
    credentials: true
}), bodyParser.json() /*express.json()*/ );

var counter_get = 0;
var counter_get_random = 0;
var counter_get_all = 0;
var counter_get_all_sorted = 0; 

// -------------------GET-------------------------
app.get("/", async (req, res) => {
    counter_get++;
    console.log("get data '/' client count: %d", counter_get);
    try {
        const data = await Sensor_Data.find().sort({
            'timestamp': -1
        }).limit(1);
        return res.status(200).json(data);
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            message: err
        });
    };
});

app.get("/random", async (req,res) => {
    counter_get_random++;
    console.log("get dta '/random' client count: %d", counter_get_random);
    try {
        const data = await Sensor_Data.aggregate([{'$sample': {'size': 1}}])
        return res.status(200).json(data);
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            message: err
        });
    };
});

app.get("/all", async (req, res) => {
    counter_get_all++;
    console.log("get data '/all' client count: %d", counter_get_all);
    try {
        const data = await Sensor_Data.find();
        return res.status(200).json(data);
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            message: err
        });
    };
});

app.get("/all/sorted", async (req, res) => {
    counter_get_all_sorted++;
    console.log("get data '/all/sorted' client count: %d", counter_get_all_sorted);
    try{
        const data = await Sensor_Data.find().sort({
            'timestamp': -1
        });
        return res.status(200).json(data);
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            message: err
        });
    };
});

// --------------------POST------------------------
app.post("/", (req, res) => {
    try {
        //console.log(req.body);
        const body_data = req.body[0];
        //console.log(req.body[0]["devices"]["esp32"][0]["connected"]);
        //res.status(200).send(body_data);
        const data = new Sensor_Data({
            // Schema for the data
            devices: {
                esp32: [{
                        connected: body_data["devices"]["esp32"][0]["connected"]
                    },
                    {
                        connected: body_data["devices"]["esp32"][1]["connected"]
                    }
                ],
                raspberrypi: {
                    connected: body_data["devices"]["raspberrypi"]["connected"]
                },
            },
            tempHum: {
                temperature_1: body_data["tempHum"]["temperature_1"],
                humidity_1: body_data["tempHum"]["humidity_1"],
                temperature_2: body_data["tempHum"]["temperature_2"],
                humidity_2: body_data["tempHum"]["humidity_2"],
            },
            waterSystem: {
                sensor_1: body_data["waterSystem"]["sensor_1"],
                sensor_2: body_data["waterSystem"]["sensor_2"],
                pumpe: body_data["waterSystem"]["pumpe"],
            },
            lufterLeds: {
                getLufter_1: body_data["lufterLeds"]["getLufter_1"],
                setLufter_1: body_data["lufterLeds"]["setLufter_1"],
                getLufter_2: body_data["lufterLeds"]["getLufter_2"],
                setLufter_2: body_data["lufterLeds"]["setLufter_2"],
                getLed: body_data["lufterLeds"]["getLed"],
                setLed: body_data["lufterLeds"]["setLed"],
            },
            energieStatus: {
                solar_1: body_data["energieStatus"]["solar_1"],
                solar_2: body_data["energieStatus"]["solar_2"],
                akku: body_data["energieStatus"]["akku"],
                strom: body_data["energieStatus"]["strom"]
            },
            settings: {
                brightness: body_data["settings"]["brightness"],
                sound: body_data["settings"]["sound"],
            }
        });
        data.save()
            .then(data => {
                console.log(data);
                return res.status(200).json(data);
            })
            .catch(err => {
                console.log(err);
                return res.status(500).send({
                    message: err
                });
            });
    } catch (err) {
        console.log(err);
        return res.status(500).send({
            message: err
        });
    }
});

// Connect to MongoDB
async function connect() {
    console.log("MongoDB connecting...")
    try {
        const client = await mongoose.connect(
            MONGO_URI, {
                useNewUrlParser: true,
                useUnifiedTopology: true,
                dbName: 'gewachshaus'
            }
        );
        console.log("MongoDB connected");
    } catch (err) {
        console.log(err);
        console.log("MongoDB reconnecting..");
        connect();
    }
}

connect();

server.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});