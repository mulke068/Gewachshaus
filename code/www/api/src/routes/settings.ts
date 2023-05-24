/* eslint-disable @typescript-eslint/no-unsafe-argument */
/* eslint-disable @typescript-eslint/no-misused-promises */
import express from "express";

const router = express.Router();

import { Main_GET, Main_POST, Main_PATCH } from "../controllers/settings/main";

router.get("/", Main_GET);
router.post("/", Main_POST);
router.patch("/:id", Main_PATCH);

export { router as Settings_Router };
