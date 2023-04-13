import express from "express";

const router = express.Router();

import { Get_Main, Post_Main } from "../controllers/sensor/main";

router.get("/", Get_Main);
router.post("/", Post_Main);

export { router as Sensor_Router}