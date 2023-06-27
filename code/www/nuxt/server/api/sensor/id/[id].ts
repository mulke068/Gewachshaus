export default defineEventHandler(async (event) => {
    const id = event.context.params.id;
    const data = await $fetch(`http://localhost:8080/sensor/id/${id}`);
    return data;
})