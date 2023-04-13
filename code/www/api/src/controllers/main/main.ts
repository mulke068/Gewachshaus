import express, { Request , Response , NextFunction} from 'express';
import path from 'path';

let get_main_number: number = 0;

async function Get_Main(req: Request, res: Response, next: NextFunction){
    get_main_number++;
    console.log("Get '/' Nr." + get_main_number);
    try {
        res.sendFile(path.join(__dirname, '/main.html'));
        console.log("Status 200: OK");
    } catch (error: any) {
        console.log("Status 500: Internal Server Error");
    }
}

export { Get_Main };