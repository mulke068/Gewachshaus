/* eslint-disable @typescript-eslint/no-misused-promises */
import express from "express";

const router = express.Router();

import { Main_GET, Main_PATCH } from "../controllers/settings/main";

router.get("/", Main_GET);
router.patch("/:id", Main_PATCH);

export { router as Settings_Router };
