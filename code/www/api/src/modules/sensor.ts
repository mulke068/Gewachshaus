import mongoose, { Schema, Document } from "mongoose";

export interface HookNextFunction {
	(error?: Error): any;
}

export interface ISensor_Data extends mongoose.Document {
	id: number;
	timestamp: Date;
	created_at: Date;
	temperature_1: number;
	humidity_1: number;
	temperature_2: number;
	humidity_2: number;
	soilMoisture_1: number;
	soilMoisture_2: number;
	statusPumpe: boolean;
	statusLufter_Low: boolean;
	statusLufter_High: boolean;
	statusLight: boolean;
	getRgbLed: string;
}

const SensorSchema = new mongoose.Schema({
	id: { type: Number /*,auto: true,unique: true,index: true*/ },
	timestamp: { type: Date /*,auto: true,default: Date.now()*/ },
	created_at: { type: Date /*,auto: true,default: Date.now()*/ },
	temperature_1: { type: Number },
	humidity_1: { type: Number },
	temperature_2: { type: Number },
	humidity_2: { type: Number },
	soilMoisture_1: { type: Number },
	soilMoisture_2: { type: Number },
	statusPumpe: { type: Boolean },
	statusLufter_Low: { type: Boolean },
	statusLufter_High: { type: Boolean },
	statusLight: { type: Boolean },
	getRgbLed: { type: String }
});

SensorSchema.pre("save", async function (next: HookNextFunction) {
	try {
		const counter: number = await mongoose
			.model("Sensor_Data")
			.countDocuments();
		const doc: any = this;
		if (doc.isNew) {
			doc.id = counter + 1;
			doc.timestamp = new Date();
			doc.created_at = new Date();
			return next();
		} else {
			doc.timestamp = new Date();
			return next();
		}
	} catch (err: any) {
		console.log(err);
	}
});

export const Sensor_Data = mongoose.model("Sensor_Data", SensorSchema);
