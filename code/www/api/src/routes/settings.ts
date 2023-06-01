/* eslint-disable @typescript-eslint/no-unsafe-argument */
/* eslint-disable @typescript-eslint/no-misused-promises */
import express from "express";

const router = express.Router();

import {
	Main_GET,
	Main_POST,
	Main_PATCH,
	Main_PATCH_BY_ID
} from "../controllers/settings/main";

router.get("/", Main_GET);
router.post("/", Main_POST);
router.patch("/", Main_PATCH);
router.patch("/:id", Main_PATCH_BY_ID);

export { router as Settings_Router };
