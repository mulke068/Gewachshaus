import express, { Express, Request, Response, NextFunction } from "express";
import http from "http";
import cors from "cors";
import bodyParser from "body-parser";
import mongoose, { ConnectOptions } from "mongoose";
//import { dotenv } from "dotenv";
import dotenv from "dotenv";
dotenv.config();
// imported files
import { Sensor_Data } from "./modules/sensors";
import { Sensor_Routes } from "./routes/sensors";
//
const app: Express = express();
const port: Number = parseInt(process.env.API_PORT as string) || 3030;
const server = http.createServer(app);
const mongodb_uri: String =
  process.env.MONGODB_URI ||
  "mongodb://root:root@127.0.0.1:27017/?authMechanism=DEFAULT";

app.use(
  cors({
    origin: true,
    credentials: true,
  }),
  bodyParser.json()
);

app.use("/", Sensor_Routes);

async function connectToDatabase() {
  try {
    console.log("Connecting to database ...");
    await mongoose.connect(
      mongodb_uri as string,
      {
        useCreateIndex: true,
        useNewUrlParser: true,
        useUnifiedTopology: true,
      } as ConnectOptions
    );
    console.log("Connected to database");
  } catch (error) {
    console.log("Error connecting to database: ");
    console.log(error);
    console.log("Retrying in 5 seconds ...");
    setTimeout(connectToDatabase, 5000);
  }
}

app.listen(port, () => {
  console.log(`Server is running on http://localhost:${port}`);
  connectToDatabase();
});
