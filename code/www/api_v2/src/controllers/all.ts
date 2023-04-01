import { Request , Response , NextFunction } from 'express';

import { Sensor_Data } from '../modules/sensors';

let get_all_number: number = 0;
let get_all_sorted_number: number = 0;
let get_all_id_number: number = 0;

async function All(req: Request, res: Response , next: NextFunction){
    get_all_number++;
    console.log("Get '/all' Nr. " + get_all_number);
    try {
        const data : any = await Sensor_Data.find();
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

async function All_Sorted(req: Request, res: Response , next: NextFunction){
    get_all_sorted_number++;
    console.log("Get '/all/sorted' Nr. " + get_all_sorted_number);
    try {
        const data : any = await Sensor_Data.find().sort({
            'timestamp': -1
        })
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

async function All_ID(req: Request, res: Response , next: NextFunction){
    get_all_id_number++;
    console.log("Get '/all/:id' Nr. " + get_all_id_number);
    try{
        const data : any = await Sensor_Data.find({'id': req.params.id});
        return res.status(200).json(data);       
    } catch (err:any){
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        })
    }
}

export { All, All_Sorted , All_ID};