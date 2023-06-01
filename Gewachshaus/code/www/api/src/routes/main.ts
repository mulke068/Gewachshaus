import express from "express";

const router = express.Router();

import { Get_Main } from "../controllers/main/main";

router.get("/", Get_Main);

export { router as Main_Router };
