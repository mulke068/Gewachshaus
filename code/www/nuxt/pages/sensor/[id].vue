import type { CustomAppConfig } from 'nuxt/schema';
import { NuxtLink } from '../../.nuxt/components';
<template>
    <NuxtLink :to="`/sensor`">
        <button class="btn btn-error">Back</button>
    </NuxtLink>
    <button @click="refresh" class="btn btn-info">Reload</button>
    <div class="grid gap-2 md:grid-cols-3 text-white-50">
        <div class="h-[auto] m-4">
            <div>ID: {{ sensor_value.id }}</div>
            <div>timestamp: {{ sensor_value.timestamp }}</div>
            <div>Created at: {{ sensor_value.created_at }}</div>
            <div>Unique ID: {{ sensor_value._id }}</div>
            <div>version: {{ sensor_value.__v }}</div>
        </div>
        <div v-for="sensor in sensor_data" :key="sensor._id" >
            <div class="grid items-center justify-center w-auto h-auto gap-4 rounded-lg grid-row-4 bg-minsk-900">
                <div class="flex h-10 space-x-8">
                    <div class="m-2 ">ID</div>
                    <div class="m-2">{{ sensor.name }}</div>
                </div>
                <div class="flex h-10 space-x-8">
                    <div class="m-2">Pin</div>
                    <div class="m-2">{{ sensor.pin }}</div>
                </div>
                <div class="flex h-10 space-x-8">
                    <div class="m-2">Value</div>
                    <div class="m-2">{{ sensor.value }}</div>
                </div>
                <div class="flex h-min[10] h-max[auto] space-x-8">
                    <div class="m-2">Description</div>
                    <div class="m-2">{{ sensor.description }}</div>
                </div>
                <div class="flex h-10 space-x-8">
                    <div class="m-2">ID</div>
                    <div class="m-2">{{ sensor._id }}</div>
                </div>
            </div>
        </div>
    </div>
</template>

<script setup lang='ts'>
const runtimeConfig = useRuntimeConfig() 
const { id } = useRoute().params
const { data, refresh } = await useFetch(`${runtimeConfig.api_host}/sensor/id/${id}`, { key: `${id}` })
const sensor_data = data.value.sensor
const sensor_value = data.value
</script>

<style scoped>
</style>