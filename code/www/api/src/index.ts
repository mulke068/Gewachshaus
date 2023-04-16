/* eslint-disable @typescript-eslint/no-misused-promises */
import express, { Express } from "express";
import cors from "cors";
import bodyParser from "body-parser";
//import { dotenv } from "dotenv";
import dotenv from "dotenv";
dotenv.config();
// imported files
import { Display_Router } from "./routes/display";
import { Sensor_Router } from "./routes/sensor";
import { Main_Router } from "./routes/main";
//
const app: Express = express();
const port: number = parseInt(process.env.API_PORT as string) || 3030;

// Connect to database
import connectDB from "./settings/db";

app.use(
  cors({
    origin: true,
    credentials: true,
  }),
  bodyParser.json()
);

app.use("/", Main_Router);
app.use("/display", Display_Router);
app.use("/sensor", Sensor_Router);

app.listen(port, async () => {
  await connectDB();
  console.log(`Server is running on http://localhost:${port}`);
});
