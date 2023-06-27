import type { CustomAppConfig } from 'nuxt/schema';
import { NuxtLink } from '../../.nuxt/components';
<template>
    <NuxtLink :to="`/sensor`">
        <button class="btn btn-error text-white-50">Back</button>
    </NuxtLink>
    <button @click="refresh" class="btn btn-info text-white-50">Reload</button>
    <div class="grid gap-2 md:grid-cols-3 text-neutral-900 dark:text-white-50">
        <div class="h-[auto] m-4">
            <div>ID: {{ sensor_value.id }}</div>
            <div>timestamp: {{ sensor_value.timestamp }}</div>
            <div>Created at: {{ sensor_value.created_at }}</div>
            <div>Unique ID: {{ sensor_value._id }}</div>
            <div>version: {{ sensor_value.__v }}</div>
        </div>
        
        <div v-for="[key,value] of Object.entries(sensor_value)" :key="sensor_value.id">
            <div class="grid items-center justify-center w-auto h-auto gap-4 rounded-lg grid-row-4 bg-minsk-900">
                <div class="flex h-min[10] h-max[auto] space-x-8 text-white-50">
                    <div class="m-2">{{ key }}</div>
                    <div class="m-2">{{ value }}</div>
                </div>
            </div>
        </div>
    </div>
</template>

<script setup lang='ts'>
const runtimeConfig = useRuntimeConfig() 
const { id } = useRoute().params
//const { data, refresh } = await useFetch(`${runtimeConfig.public.api_host}/sensor/id/${id}`, { key: `${id}` })
const { data } = await useFetch(`/api/sensor/id/${id}`, {key: `${id}`})
const sensor_value: any = data.value
</script>

<style scoped>
</style>