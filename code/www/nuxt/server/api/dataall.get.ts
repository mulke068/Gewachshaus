export default defineEventHandler(async(event)=>{
    const data = await fetch('http://localhost:8080/all').then(res=> res.json())
    return data
})
