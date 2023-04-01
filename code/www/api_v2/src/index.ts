import express, { Express, Request, Response, NextFunction } from "express";
import cors from "cors";
import bodyParser from "body-parser";
import mongoose from "mongoose";
//import { dotenv } from "dotenv";
import dotenv from "dotenv";
dotenv.config();
// imported files
import { All_Router } from "./routes/main";
//
const app: Express = express();
const port: Number = parseInt(process.env.API_PORT as string) || 3030;

// Connect to database
import connectDB from "./settings/db";

app.use(
  cors({
    origin: true,
    credentials: true,
  }),
  bodyParser.json()
);

app.use("/", All_Router);

app.listen(port, async () => {
  await connectDB();
  console.log(`Server is running on http://localhost:${port}`);
});
