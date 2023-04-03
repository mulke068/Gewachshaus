import { Request , Response , NextFunction } from 'express';

import { Sensor_Data } from '../modules/sensors';

let get_all_number: number = 0;
let get_all_sorted_number: number = 0;
let get_all_categories_names_number = 0;

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
/*
async function All_Categories_Names(req: Request<{category: string, name: string},{},{},{}>, res: Response, next: NextFunction){
    get_all_categories_names_number++;
    console.log("Get '/all/categories/categorie/name' Nr. "+ get_all_categories_names_number);
    console.log(`Get '/all/categories/${req.params.category}/${req.params.name}`);
    try {
        const filter: any = {};
        const projection : any = {
            [req.params.category]: 1,
            [req.params.name]: 1
        };
        const data : any = await Sensor_Data.find(filter, { projection });
        return res.status(200).json(data);
    } catch (err :any ) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        })
    }
}
*/
// Request<{, name: string},{},{},{}>, res: Response, next: NextFunction


// https://mongoosejs.com/docs/api/aggregate.html#Aggregate.prototype.project()
async function All_Categories_Names(req: Request<{name: string},{},{},{}>, res: Response, next: NextFunction){
    get_all_categories_names_number++;
    console.log("Get '/all/categories/name' Nr. "+ get_all_categories_names_number);
    console.log(`Get '/all/categories/${req.params.name}`);
    try {
        //const filter: any = {};
        const projection : any = {
            [req.query.name]: 1,
            _id: 1,
            created_at: 1
        };
        const data : any = await Sensor_Data.aggregate().project(projection);
        console.log(data);
        return res.status(200).json(data);
    } catch (err :any ) {
        console.log(err);
        return res.status(500).send({
            message: {
                "info": "Some error occurred while retrieving the data.",
                "error": err.message
            }
        })
    }
}

export { All, All_Sorted , All_Categories_Names };