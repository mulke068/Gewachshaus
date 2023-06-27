export default defineEventHandler(async (event) => {
    const config = useRuntimeConfig();
    const setBody = await readBody(event);
    const res = await $fetch(`${config.public.api_host}/settings`, {
        method: 'PATCH',
        headers: {
            'Content-Type': 'application/json'
        },
        body: setBody
    });
})