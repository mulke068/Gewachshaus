import mongoose, { Schema, Document } from "mongoose";

export interface HookNextFunction {
	(error?: Error): any;
}

export interface ISensor_Data extends mongoose.Document {
	id: number;
	timestamp: Date;
	created_at: Date;
	sensor: [
		{
			name: string;
			pin: string;
			value: string;
			description: string;
		}
	];
}

const SensorSchema = new mongoose.Schema({
	id: { type: Number /*,auto: true,unique: true,index: true*/ },
	timestamp: { type: Date /*,auto: true,default: Date.now()*/ },
	created_at: { type: Date /*,auto: true,default: Date.now()*/ },
	temperature_1: { type: Number },
	humidity_1: { type: Number },
	temperature_2: { type: Number },
	humidity_2: { type: Number },
	soliMoisture_1: { type: Number },
	soliMoisture_2: { type: Number },
	statusPumpe: { type: Boolean },
	statusLufter_1: { type: Boolean },
	statusLufter_2: { type: Boolean },
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
