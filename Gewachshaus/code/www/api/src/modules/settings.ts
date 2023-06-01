import mongoose, { Schema, Document } from "mongoose";

export interface HookNextFunction {
	(error?: Error): any;
}

export interface ISettings_Data extends mongoose.Document {
	id: number;
	timestamp: Date;
	created_at: Date;
	temperature_Min: number;
	temperature_Avg: number;
	temperature_Max: number;
	soilMoisture_Min: number;
	soilMoisture_Max: number;
	setLufter_1: boolean;
	setLufter_2: boolean;
	setPumpe: boolean;
	setLight: boolean;
	setRgbled: string;
	setMatrixLed: string;
}

const SettingsSchema = new mongoose.Schema({
	id: { type: Number /*,auto: true,unique: true,index: true*/ },
	timestamp: { type: Date /*,auto: true,default: Date.now()*/ },
	created_at: { type: Date /*,auto: true,default: Date.now()*/ },
	temperature_Min: { type: Number /*, default: 18 */ },
	temperature_Avg: { type: Number /*, default: 22 */ },
	temperature_Max: { type: Number /*, default: 30 */ },
	soilMoisture_Min: { type: Number /*, default: 0 */ },
	soilMoisture_Max: { type: Number /*, default: 100 */ },
	setLufter_1: { type: Boolean /*, default: false */ },
	setLufter_2: { type: Boolean /*, default: false */ },
	setPumpe: { type: Boolean /*, default: false */ },
	setLight: { type: Boolean /*, default: false */ },
	setRgbLed: { type: String /*, default: "0,0,0" */ },
	setMatrixLed: { type: String /*, default: "Text" */ }
});

SettingsSchema.pre("save", async function (next: HookNextFunction) {
	try {
		const counter: number = await mongoose
			.model("Settings_Data")
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

export const Settings_Data = mongoose.model("Settings_Data", SettingsSchema);
