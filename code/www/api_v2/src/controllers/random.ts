import express , { Request , Response , NextFunction } from 'express';

import { Sensor_Data } from '../modules/sensors';

let get_random_number: number= 0;

async function Get_Random(req: Request , res: Response , next: NextFunction) {
    get_random_number++;
    console.log("Get '/random' Nr. " + get_random_number);
    try {
        const data : any = await Sensor_Data.aggregate([{$sample: {size: 1}}]);
        return res.status(200).json(data);
    } catch ( err : any) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        })
    }
}

export { Get_Random};