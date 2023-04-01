import express ,{ Express, Request, Response , NextFunction} from 'express';

const router = express.Router();

import { Get_Main ,Post_Main } from "../controllers/main";
import { Get_Random } from "../controllers/random";
import { All, All_ID, All_Sorted } from '../controllers/all';

router.get("/", Get_Main);
router.post("/", Post_Main);
// 
router.get("/random", Get_Random);
//
router.get("/all", All);
router.get("/all/sorted" , All_Sorted);
router.get("/all/:id", All_ID);


export { router as All_Router };