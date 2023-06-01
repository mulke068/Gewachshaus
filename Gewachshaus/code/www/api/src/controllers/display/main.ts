/* eslint-disable @typescript-eslint/ban-types */
/* eslint-disable @typescript-eslint/no-unsafe-assignment */
/* eslint-disable @typescript-eslint/no-unused-vars */
import { Request, Response, NextFunction } from "express";

import { Display_Data } from "../../modules/display";

let get_main_number = 0;
let get_main_by_id_number = 0;
let post_main_number = 0;

async function Get_Main(req: Request, res: Response, next: NextFunction) {
	get_main_number++;
	console.log("Get '/display' Nr. " + String(get_main_number));
	try {
		const data: unknown = await Display_Data.find()
			.sort({
				timestamp: -1
			})
			.limit(1);
		return res.status(200).send(data);
	} catch (err: any) {
		console.log(err);
		return (
			res.status(500).send({
				message: {
					info: "Some error occurred while retrieving the data.",
					error: err.message
				}
			}) && console.log("Status 500: Internal Server Error")
		);
	}
}

async function Get_Main_By_ID(
	req: Request<{ id?: string }, {}, {}, {}>,
	res: Response,
	next: NextFunction
) {
	get_main_by_id_number++;
	console.log("Get '/display/id/:id' Nr." + String(get_main_by_id_number));
	console.log(`Get '/display/id/${String(req.params.id)}`);
	try {
		const data: unknown = await Display_Data.find({ id: req.params.id });
		return res.status(200).send(data);
	} catch (err: any) {
		console.log(err);
		return (
			res.status(500).send({
				message: {
					info: "Some error occurred while retrieving the data.",
					error: err.message
				}
			}) && console.log("Status 500: Internal Server Error")
		);
	}
}

async function Post_Main(req: Request, res: Response, next: NextFunction) {
	post_main_number++;
	console.log("Post '/display' Nr. " + String(post_main_number));
	try {
		const data: unknown = await Display_Data.create(req.body);
		//console.log(data);
		return res.status(201).json(data);
	} catch (err: any) {
		console.log(err);
		return (
			res.status(500).send({
				message: {
					info: "Some error occurred while retrieving the data.",
					error: err.message
				}
			}) && console.log("Status 500: Internal Server Error")
		);
	}
}

export { Get_Main, Get_Main_By_ID, Post_Main };
