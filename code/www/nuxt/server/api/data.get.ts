export default defineEventHandler(async (event) => {
    const output = await fetch('http://localhost:8080')
    const data = await output.json()
    return {
        statusCode: 200,
        data: data
    }
});