/* eslint-disable @typescript-eslint/ban-types */
/* eslint-disable @typescript-eslint/no-unused-vars */
/* eslint-disable @typescript-eslint/no-unsafe-assignment */
import { Response, Request, NextFunction } from "express";

import { Sensor_Data } from "../../modules/sensor";
// 32 pinlayouts

let get_main_number = 0;
let post_main_number = 0;
let get_main_by_id_number = 0;

async function Get_Main(req: Request, res: Response, next: NextFunction) {
	get_main_number++;
	console.log("Get '/sensor' Nr." + String(get_main_number));
	try {
		const data: unknown = await Sensor_Data.findOne()
			.sort({
				timestamp: -1
			})
			.limit(1);
		return res.status(200).json(data) && console.log("Status 200");
	} catch (err: any) {
		console.log(err);
		return (
			res.status(500).json({
				message: {
					info: "Some error occurred while retrieving the data.",
					error: err.message
				}
			}) && console.log("Status 500")
		);
	}
}

async function Get_Main_By_Id(
	req: Request<{ id?: string }, {}, {}, {}>,
	res: Response,
	next: NextFunction
) {
	get_main_by_id_number++;
	console.log("Get '/sensor/id/:id Nr." + String(get_main_by_id_number));
	console.log("Get '/sensor/id/" + String(req.params.id));
	try {
		if (!req.params.id || req.params.id === ":id") {
			return (
				res.status(406).json({
					message: {
						info: "No id provided."
					}
				}) && console.log("Status 406")
			);
		} else {
			const data: any = await Sensor_Data.findById(req.params.id); // find by unique id
			// const data: any = await Sensor_Data.find({ id: req.params.id }); // find by id
			if (!data || data.length === 0) {
				return (
					res.status(404).json({
						message: {
							info: "No data found with id " + String(req.params.id)
						}
					}) && console.log("Status 404")
				);
			} else {
				return res.status(200).json(data) && console.log("Status 200");
			}
		}
	} catch (err: any) {
		res.status(500).json({
			message: {
				info: "Some error occurred while retrieving the data.",
				error: err.message
			}
		}) && console.log("Status 500");
	}
}

async function Post_Main(req: Request, res: Response, next: NextFunction) {
	post_main_number++;
	console.log("Post '/sensor' Nr." + String(post_main_number));
	try {
		if (!req.body) {
			return (
				res.status(204).json({
					message: {
						info: "No data provided."
					}
				}) && console.log("Status 204")
			);
		} else {
			const data: any = await Sensor_Data.create(req.body);
			//console.log(data);
			return res.status(201).json(data) && console.log("Status 201");
		}
	} catch (err: any) {
		return (
			res.status(500).json({
				message: {
					info: "Some error occurred while retrieving the data.",
					error: err.message
				}
			}) && console.log("Status 500")
		);
	}
}

export { Get_Main, Post_Main, Get_Main_By_Id };
