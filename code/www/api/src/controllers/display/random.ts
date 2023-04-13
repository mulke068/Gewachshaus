import express , { Request , Response , NextFunction } from 'express';

import { Display_Data } from '../../modules/display';

let get_random_number: number= 0;

async function Get_Random(req: Request , res: Response , next: NextFunction) {
    get_random_number++;
    console.log("Get '/display/random' Nr. " + get_random_number);
    try {
        const data : any = await Display_Data.aggregate([{$sample: {size: 1}}]);
        return res.status(200).json(data) &&
            console.log("Status 200: OK");
    } catch ( err : any) {
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

export { Get_Random};