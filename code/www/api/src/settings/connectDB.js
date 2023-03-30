const mongoose = require('mongoose');
const MONGO_URI = process.env.MONGO_URI || "mongodb://root:root@127.0.0.1:27017/?authMechanism=DEFAULT";

// Connect to MongoDB
async function connectDB() {
    console.log("MongoDB connecting...")
    try {
        const client = await mongoose.connect(
            MONGO_URI, {
                useNewUrlParser: true,
                useUnifiedTopology: true,
                dbName: 'gewachshaus'
            }
        );
        console.log("MongoDB connected");
    } catch (err) {
        console.log(err);
        console.log("MongoDB reconnecting..");
        connect();
    }
}

module.exports = {
    connectDB: connectDB
}