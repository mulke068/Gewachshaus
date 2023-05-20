/* eslint-disable @typescript-eslint/ban-types */
/* eslint-disable @typescript-eslint/no-unsafe-call */
/* eslint-disable @typescript-eslint/no-unsafe-assignment */
/* eslint-disable @typescript-eslint/no-unused-vars */
import { Request, Response, NextFunction } from "express";
import { Settings_Data } from "../../modules/settings";

let get_settings_number = 0;
let update_settings_number = 0;

async function Get(req: Request, res: Response, next: NextFunction) {
	get_settings_number++;
	console.log("GET '/settings' Nr." + String(get_settings_number));
	try {
		const data = await Settings_Data.find({
			timestamp: -1
		});
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
		const data = await Settings_Data.updateOne(
			{
				id: req.params.id || "1"
			},
			{
				$set: req.body
			}
		);
		return res.status(201).json(data) && console.log("Status 201");
	} catch (err: any) {
		return (
			res.status(500).json({
				info: "Error while updating settings data",
				error: err.message
			}) && console.log("Status 500")
		);
	}
}

export { Get as Main_GET, Update as Main_PATCH };
