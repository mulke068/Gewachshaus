import express from "express";

const router = express.Router();

import {
  Get_Main,
  Post_Main,
  Get_Main_By_Id,
} from "../controllers/sensor/main";

router.get("/", Get_Main);
router.post("/", Post_Main);
router.get("/id/:id", Get_Main_By_Id);

export { router as Sensor_Router };
