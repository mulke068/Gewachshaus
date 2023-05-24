/* eslint-disable @typescript-eslint/ban-types */
/* eslint-disable @typescript-eslint/no-unsafe-call */
/* eslint-disable @typescript-eslint/no-unsafe-assignment */
/* eslint-disable @typescript-eslint/no-unused-vars */
import { Request, Response, NextFunction } from "express";
import { Settings_Data } from "../../modules/settings";

let get_settings_number = 0;
let update_settings_number = 0;
let post_settings_number = 0;

async function Get(req: Request, res: Response, next: NextFunction) {
	get_settings_number++;
	console.log("GET '/settings' Nr." + String(get_settings_number));
	try {
		const data: any = await Settings_Data.find()
			.sort({
				timestamp: -1
			})
			.limit(1);
		return res.status(200).json(data) && console.log("Status 200");
	} catch (err: any) {
		return (
			res.status(500).json({
				info: "Error while getting settings data",
				error: err.message
			}) && console.log("Status 500")
		);
	}
}

async function Post(req: Request, res: Response, next: NextFunction) {
	post_settings_number++;
	console.log("POST '/settings' Nr. " + String(post_settings_number));
	try {
		if (!req.body) {
			return (
				res.status(204).json({
					info: "No body provided"
				}) && console.log("Status 204")
			);
		} else {
			const data: any = await Settings_Data.create(req.body);
			return res.status(201).json(data) && console.log("Status 201");
		}
	} catch (err: any) {
		return (
			res.status(500).json({
				info: "Error while posting settings data",
				error: err.message
			}) && console.log("Status 500")
		);
	}
}

async function Update(
	req: Request<{ id?: string }, {}, {}, {}>,
	res: Response,
	next: NextFunction
) {
	update_settings_number++;
	console.log(
		"PATCH '/settings/" +
			String(req.params.id) +
			"' Nr." +
			String(update_settings_number)
	);
	try {
		const data: any = await Settings_Data.updateOne(
			{
				id: req.params.id
			},
			{
				$set: req.body
			}
		);
		if (data.matchedCount === 0) {
			return (
				res.status(404).json({
					info: "No settings data found"
				}) && console.log("Status 404")
			);
		} else {
			return res.status(202).json(data) && console.log("Status 202");
		}
	} catch (err: any) {
		return (
			res.status(500).json({
				info: "Error while updating settings data",
				error: err.message
			}) && console.log("Status 500")
		);
	}
}

export { Get as Main_GET, Post as Main_POST, Update as Main_PATCH };
