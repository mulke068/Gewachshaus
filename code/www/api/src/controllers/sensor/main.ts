import express, {Response , Request , NextFunction} from 'express';

// 32 pinlayouts

let get_main_number: number = 0;
let post_main_number: number = 0;

async function Get_Main(req: Request, res: Response, next: NextFunction){
    get_main_number++;
    console.log("Get '/sensor' Nr."+ get_main_number);
    try {

    } catch (err: any) {
        console.log(err);

    }
}

async function Post_Main(req: Request, res: Response, next: NextFunction){
    post_main_number++;
    console.log("Post '/sensor' Nr."+ post_main_number);
    try {
        let i = 0;
        for (;i < req.body.length; i++) {
            console.log(req.body[i]["id"]);   
        }
        console.log(i);
        res.status(200).json(req.body);
    } catch (err: any) {
        console.log(err);
        res.status(500).json({
            message: "Internal Server Error",
            error: err.message
        });
    }
}

export {Get_Main, Post_Main}