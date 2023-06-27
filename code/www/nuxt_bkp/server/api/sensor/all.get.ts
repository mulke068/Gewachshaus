export default defineEventHandler(async (event) => {
    const config = useRuntimeConfig();
    const data = await $fetch(`${config.public.api_host}/sensor/all`);
    return data;
})