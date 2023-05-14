/* eslint-disable @typescript-eslint/no-unsafe-assignment */

import { Request, Response, NextFunction } from "express";
import { Sensor_Data } from "../../modules/sensor";

let get_all_number = 0;

async function Get_All(req: Request, res: Response, next: NextFunction) {
	get_all_number++;
	console.log("GET '/sensor/all' Nr." + String(get_all_number));
	try {
		const data: unknown = await Sensor_Data.find()
			.sort({ timestamp: -1 })
			.limit(100);
		return res.status(200).json(data) && console.log("Status 200");
	} catch (err: any) {
		res.status(500).json({
			message: {
				info: "Some error occurred while retrieving the data.",
				error: err.message
			}
		}) && console.log("Status 500");
	}
}

export { Get_All };
