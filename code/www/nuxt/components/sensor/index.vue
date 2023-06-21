import type { CustomAppConfig from 'nuxt/schema'};
<template>
        <button @click="reload" class="my-4 btn btn-info text-white-50">Refresh</button>
        <div v-if="error" class="animate-pulse">
            <div class="flex items-center justify-center space-x-2">
	            <div class="w-4 h-4 rounded-full animate-pulse dark:bg-white-600"></div>
	            <div class="w-4 h-4 rounded-full animate-pulse dark:bg-white-600"></div>
	            <div class="w-4 h-4 rounded-full animate-pulse dark:bg-white-600"></div>
            </div>
        </div>
        <div v-else>
            <div class="grid gap-4 md:grid-cols-2 text-white-50">
                <section v-for="data_row in data" :key="data_row._id" >
                    <div class="grid items-center justify-center w-max[auto] h-auto gap-4 rounded-lg bg-minsk-900">
                        <div class="flex h-10 space-x-8">
                            <div class="m-2 ">ID</div>
                            <div class="m-2">{{ data_row.id }}</div>
                        </div>
                        <div class="flex h-10 space-x-8">
                            <div class="m-2">Timestamp</div>
                            <div class="m-2">{{ data_row.timestamp }}</div>
                        </div>
                        <div class="h-max[auto]">
                            <NuxtLink :to="`/sensor/${data_row._id}`">
                                <button class="m-2 btn btn-outline btn-info">Show Me</button>
                            </NuxtLink>
                        </div>
                    </div>
                </section >
            </div>
        </div>
</template>

<script lang="ts">
export default {
    data() {
        return {
            data: {
                timestamp: 0,
                id: 0,
                _id: 0
            },
            reload: () => this.refresh(),
            error: []
        }
    },
    beforeMount() {
        this.refresh()
    },
    mounted() {
        this.refresh()
        this.intervalId = setInterval(() => {
            this.refresh()
        }, 5000)
    },
    beforeUnmount() {
        clearInterval(this.intervalId);
    },
    methods: {
        async refresh() {
            const runtimeConfig = useRuntimeConfig()
            const { data , error } = await useFetch(`${runtimeConfig.api_host}/sensor/all`)
            this.error = error
            this.data = data.value
        }
    }
}
</script>

<!--script lang="ts" setup>
    const runtimeConfig = useRuntimeConfig()
    const { data, refresh } = await useFetch(`${runtimeConfig.api_host}/sensor/all`)
</script-->
