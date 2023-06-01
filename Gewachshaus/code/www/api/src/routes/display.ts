/* eslint-disable @typescript-eslint/no-misused-promises */
import express from "express";

const router = express.Router();

import {
  Get_Main,
  Get_Main_By_ID,
  Post_Main,
} from "../controllers/display/main";
import { Get_Random } from "../controllers/display/random";
import {
  All,
  All_Sorted,
  All_Categories,
  All_Categories_Names,
} from "../controllers/display/all";

router.get("/", Get_Main);
router.get("/id/:id", Get_Main_By_ID);
router.post("/", Post_Main);
//
router.get("/random", Get_Random);
//
router.get("/all", All);
router.get("/all/sorted", All_Sorted);
router.get("/all/categories/:category", All_Categories);
router.get("/all/categories/:category/:name", All_Categories_Names);

export { router as Display_Router };
