export default defineEventHandler(async (event) => {
    const data = await $fetch('http://localhost:8080/sensor');
    return data;
})