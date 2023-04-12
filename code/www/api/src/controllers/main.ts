import { Request, Response , NextFunction} from 'express';

import { Display_Data }from "../modules/sensors";

let get_main_number: number = 0;
let get_main_by_id_number: number = 0;
let post_main_number: number = 0;

async function Get_Main(req: Request, res: Response , next: NextFunction) {
    get_main_number++;
    console.log("Get '/' Nr. " + get_main_number);
    try {
        const data: any = await Display_Data.find().sort({
            'timestamp': -1
        }).limit(1);
        return res.status(200).send(data);
    } catch (err: any ) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        });
    }
}

async function Get_Main_By_ID(req: Request<{id?: string},{},{},{}>, res: Response , next: NextFunction){
    get_main_by_id_number++;
    console.log("Get '/id/:id' Nr."+ get_main_by_id_number);
    console.log(`Get '/id/${req.params.id}`)
    try{
        const data : any = await Display_Data.find({'id': req.params.id})
        return res.status(200).send(data) && 
            console.log("Status 200: OK");
    } catch (err: any) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        }) && 
            console.log("Status 500: Internal Server Error");
    }
}

async function Post_Main( req: Request, res: Response , next: NextFunction) {
    post_main_number++;
    console.log("Post '/' Nr. " + post_main_number);
    try {
        const data : any = await Display_Data.create(req.body);        
        console.log(data);
        return res.status(200).json(data) && 
            console.log("Status 200: OK");
    } catch (err : any) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        }) &&
            console.log("Status 500: Internal Server Error");
    }
}

export { Get_Main, Get_Main_By_ID , Post_Main };