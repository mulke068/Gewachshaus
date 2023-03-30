import { Request, Response , NextFunction} from 'express';

import { Sensor_Data }from "../modules/sensors";

let get_main_number: number = 0;
let post_main_number: number = 0;

async function Get_Main(req: Request, res: Response , next: NextFunction) {
    get_main_number++;
    console.log("Get '/' Nr. " + get_main_number);
    try {
        const data: any = await Sensor_Data.find().sort({
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

async function Post_Main( req: Request, res: Response , next: NextFunction) {
    post_main_number++;
    console.log("Post '/' Nr. " + post_main_number);
    try {
        const req_data : any = await Sensor_Data.find().sort({
            'timestamp': -1
        })
        const data : any = await Sensor_Data.create(req.body);
        
        console.log(data);
        return res.status(200).json(data);
    } catch (err : any) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        })
    }
}

export { Get_Main , Post_Main };