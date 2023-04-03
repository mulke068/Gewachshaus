import express ,{ Express, Request, Response , NextFunction} from 'express';

const router = express.Router();

import { Get_Main ,Get_Main_By_ID,Post_Main } from "../controllers/main";
import { Get_Random } from "../controllers/random";
import { All, All_Categories_Names , All_Sorted } from '../controllers/all';

router.get("/", Get_Main);
router.get("/id/:id", Get_Main_By_ID);
router.post("/", Post_Main);
// 
router.get("/random", Get_Random);
//
router.get("/all", All);
router.get("/all/sorted" , All_Sorted);
//router.get("/all/categories/:category/:name", All_Categories_Names);
router.get("/all/categories/:name", All_Categories_Names);


export { router as All_Router };