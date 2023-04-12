import { Request , Response , NextFunction } from 'express';

import { Display_Data } from '../modules/sensors';

let get_all_number: number = 0;
let get_all_sorted_number: number = 0;
let get_all_categories_number: number = 0;
let get_all_categories_names_number: number = 0;

async function All(req: Request, res: Response , next: NextFunction){
    get_all_number++;
    console.log("Get '/all' Nr. " + get_all_number);
    try {
        const data : any = await Display_Data.find();
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

async function All_Sorted(req: Request, res: Response , next: NextFunction){
    get_all_sorted_number++;
    console.log("Get '/all/sorted' Nr. " + get_all_sorted_number);
    try {
        const data : any = await Display_Data.find().sort({
            'timestamp': -1
        })
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

async function All_Categories(req: Request<{category: string},{},{},{}>, res: Response, next: NextFunction){
    get_all_categories_number++;
    console.log("Get '/all/categories' Nr."+get_all_categories_number);
    console.log(`Get '/all/${req.params.category}'`);
    try {
        let search : string;
        if (!req.params.category || req.params.category == " ") {
            return res.status(400).send({message: "Category can not be empty"}) &&
                console.log("Status 400: Bad Request");
        } else {
            search = req.params.category;
        }
        const projection : any = {
            [search]: 1,
            _id: 1,
            created_at: 1
        }
        const data : any = await Display_Data.aggregate().project(projection);
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

// https://mongoosejs.com/docs/api/aggregate.html#Aggregate.prototype.project()
async function All_Categories_Names(req: Request<{category: string ,name: string},{},{},{}>, res: Response, next: NextFunction){
    get_all_categories_names_number++;
    console.log("Get '/all/categories/categorie/name' Nr. "+ get_all_categories_names_number);
    console.log(`Get '/all/categories/${req.params.category}/${req.params.name}`);
    try {
        let search : string;
        if (!req.params.name || req.params.name == " ") {
            return res.status(400).send({message: "Category name can not be empty"}) && 
                console.log("Status 400: Bad Request");
        } else {
            search = req.params.category + "." + req.params.name;
        }
        const projection : any = {
            [search]: 1,
            _id: 1,
            created_at: 1
        };
        const data : any = await Display_Data.aggregate().project(projection);
        return res.status(200).json(data) && 
            console.log("Status 200: OK");
    } catch (err :any ) {
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

export { All, All_Sorted, All_Categories , All_Categories_Names };