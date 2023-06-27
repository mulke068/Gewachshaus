export default defineEventHandler(async (event) => {
    const data = await $fetch('http://localhost:8080/settings');
    return data;
})