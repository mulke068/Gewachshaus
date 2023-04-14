import {Response , Request , NextFunction} from 'express';

// 32 pinlayouts

let get_main_number: number = 0;
let post_main_number: number = 0;

async function Get_Main(req: Request, res: Response, next: NextFunction){
    get_main_number++;
    console.log("Get '/sensor' Nr."+ String(get_main_number));
    try {
        return res.status(200)
    } catch (err: any) {
        console.log(err);
        return res.status(500).json({
            message: "Internal Server Error",
            error: err.message
        });
    }
}

async function Post_Main(req: Request, res: Response, next: NextFunction){
    post_main_number++;
    console.log("Post '/sensor' Nr."+ String(post_main_number));
    try {
        let counter: number = 0;
        for (let i:number = 0;i < req.body.length; i++, counter++) {
            console.log(req.body[i]["id"]);   
        }
        console.log(counter);
        return res.status(200).json(req.body);
    } catch (err: any) {
        console.log(err);
        return res.status(500).json({
            message: "Internal Server Error",
            error: err.message
        });
    }
}

export {Get_Main, Post_Main}