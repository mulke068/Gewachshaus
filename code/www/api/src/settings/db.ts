/* eslint-disable @typescript-eslint/no-misused-promises */
import mongoose, { ConnectOptions } from "mongoose";
import dotenv from "dotenv";
dotenv.config();

const mongodb_uri: String =
  process.env.MONGODB_URI ||
  "mongodb://root:root@localhost:27017/?authMechanism=DEFAULT";
  //"mongodb://root:root@127.0.0.1:27017/?authMechanism=DEFAULT";

const connectDB = async ()=> {
  try {
    console.log("Connecting to database ...");
    await mongoose.connect(
      mongodb_uri as string,
      {
        useNewUrlParser: true,
        useUnifiedTopology: true,
        dbName: 'gewachshaus'
      } as ConnectOptions
    );
    console.log("Connected to database");
  } catch (error) {
    console.log("Error connecting to database: ");
    console.log(error);
    console.log("Retrying in 5 seconds ...");
    setTimeout(connectDB, 5000);
  }
}

export default connectDB;