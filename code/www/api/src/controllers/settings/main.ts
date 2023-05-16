/* eslint-disable @typescript-eslint/no-unused-vars */
import { Request, Response, NextFunction } from "express";
// import { Settings_Data } from "../../models/settings";

let get_settings_number = 0;
let update_settings_number = 0;

function Get(req: Request, res: Response, next: NextFunction) {
	get_settings_number++;
	console.log("GET '/settings' Nr." + String(get_settings_number));
	return res
		.status(200)
		.json({ message: "GET '/settings' Nr." + String(get_settings_number) });
}

function Update(req: Request, res: Response, next: NextFunction) {
	update_settings_number++;
	console.log("PATCH '/settings' Nr." + String(update_settings_number));
	return res.status(200).json({
		message: "PATCH '/settings' Nr." + String(update_settings_number)
	});
}

export { Get as Main_GET, Update as Main_PATCH };
