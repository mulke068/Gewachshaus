import express ,{ Express, Request, Response , NextFunction} from 'express';

const router = express.Router();

function main(req: Request, res: Response , next: NextFunction) {
    console.log("main");
    res.status(200).send("Hello World");
}

router.get("/", main);

export { router as Sensor_Routes}