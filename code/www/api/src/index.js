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


//
const { connectDB } = require("../src/settings/connectDB.js");
const Sensor_Data = require("../src/modules/data.js");
const router = require("../src/routes/sensor_data.js");
// -------------------CORS-------------------------
app.use(cors({
    origin: true,
    credentials: true
}), bodyParser.json() /*express.json()*/ );


app.use("/",  router);


connectDB();

server.listen(port, () => {
    console.log(`Example app listening at http://localhost:${port}`);
});