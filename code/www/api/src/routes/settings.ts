import express from "express";

const router = express.Router();

import { Main_GET, Main_PATCH } from "../controllers/settings/main";

router.get("/", Main_GET);
router.patch("/", Main_PATCH);

export { router as Settings_Router };
