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
      id: string;
      value: number;
    }
  ];
}

const SensorSchema = new mongoose.Schema({
  id: { type: Number /*,auto: true,unique: true,index: true*/ },
  timestamp: { type: Date /*,auto: true,default: Date.now()*/ },
  created_at: { type: Date /*,auto: true,default: Date.now()*/ },
  sensor: [
    {
      id: String,
      value: Number,
    },
  ],
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
