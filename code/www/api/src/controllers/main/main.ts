import { Request, Response, NextFunction } from "express";
//import path from "path";

let get_main_number = 0;

function Get_Main(req: Request, res: Response, next: NextFunction) {
  get_main_number++;
  console.log("Get '/' Nr." + String(get_main_number));
  try {
    //res.sendFile(path.join(__dirname, "/main.html"));
    const data =
      // eslint-disable-next-line quotes
      '<!DOCTYPE html><html lang="de"> <head> <meta charset="UTF-8" /> <meta http-equiv="X-UA-Compatible" content="IE=edge" /> <meta name="viewport" content="width=device-width, initial-scale=1.0" /> <title>Home</title> </head> <body> <style> * { margin: 0; padding: 0; box-sizing: border-box; } .content { position: absolute; top: 50%; left: 50%; transform: translate(-50%, -50%); border: 1px solid black; border-radius: 10px; padding: 20px; font-family: sans-serif; } </style> <div class="content"> <h1>Rest API</h1> <div> <h2>Display</h2> <h3>Get</h3> <div> <span>Latest Data</span> <a href="/display"><code>/display</code></a> </div> <div> <span>By id </span> <a href="/display/id/:id"><code>/display/id/:id</code></a> </div> <div> <span>Random</span> <a href="/display/random"><code>/display/random</code></a> </div> <div> <span>All</span> <a href="/display/all"><code>/display/all</code></a> </div> <div> <span>All Sorted</span> <a href="/display/all/sorted"><code>/display/all/sorted</code></a> </div> <div> <span>All Category</span> <a href="/display/all/categories/:category" ><code>/display/all/categories/:category</code></a > </div> <div> <span>All Category By Name</span> <a href="/display/all/categories/:category/:name" ><code>/display/all/categories/:category/:name</code></a > </div> <h3>Post</h3> <div> <span>New entry</span> <a href="/display"><code>/display</code></a> </div> </div> <div> <h2>Sensor</h2> <h3>Get</h3> <div> <span>Latest Data</span> <a href="/sensor"><code>/sensor</code></a> </div> <h3>Post</h3> <div> <span>New entry</span> <a href="/sensor"><code>/sensor</code></a> </div> </div> </div> </body></html>';
    res.status(200).send(data) && console.log("Status 200: OK");
  } catch (error: unknown) {
    res.status(500).send("Internal Server Error") &&
      console.log("Status 500: Internal Server Error");
  }
}

export { Get_Main };
