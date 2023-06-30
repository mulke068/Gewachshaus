import { Context } from '@nuxt/types';
<template>
    <div v-if="!error">
        <div class="container md:flex text-white-50 dark:text-white-300">
            <div class="container py-2 md:w-40 bg-clementine-700">
                <div>
                    <div class="flex justify-center text-3xl ">Devices</div>
                    <div class="p-4 text-lg ">
                        <div>Display</div>
                        <DashboardOnOff class="flex justify-center p-3" :value="false" />
                        <div>Sensors</div>
                        <DashboardOnOff class="flex justify-center p-3" :value="false" />
                        <div>Raspberry PI</div>
                        <DashboardOnOff class="flex justify-center p-3" :value="false" />
                    </div>
                </div>
            </div>
            <div class="container p-2 px-3 bg-minsk-900">
                <div>
                    <div class="flex text-3xl">Temperatur System</div>
                    <div class="justify-center p-4 space-x-8 text-lg xl:flex">
                        <div>Senors 1</div>
                        <div class="p-4 space-x-6 md:flex">
                            <DashboardCirqualPorgress :value="sensorData.temperature_1" :max="80" :min="0" :unit="'°C'" />
                            <DashboardCirqualPorgress :value="sensorData.humidity_1" :max="100" :min="0" :unit="'%'" />
                        </div>
                        <div>Senors 2</div>
                        <div class="p-4 space-x-6 md:flex">
                            <DashboardCirqualPorgress :value="sensorData.temperature_2" :max="80" :min="0" :unit="'°C'" />
                            <DashboardCirqualPorgress :value="sensorData.humidity_2" :max="100" :min="0" :unit="'%'" />
                        </div>
                    </div>
                </div>
                <div>
                    <div class="justify-start text-3xl ">Wasser System</div>
                    <div class="justify-center p-4 space-x-4 text-lg md:flex">
                        <div>
                            <div>Bodenfeuchtikeit Sensor 1</div>
                            <div class="p-4 space-x-6 md:flex">
                                <div class="radial-progress" :style="`--value: ${sensorData.soilMoisture_1}`">{{sensorData.soilMoisture_1}}</div>
                            </div>
                        </div>
                        <div>
                            <div>Bodenfeuchtikeit Sensor 2</div>
                            <div class="p-4 space-x-6 md:flex">
                                <div class="radial-progress" :style="`--value: ${sensorData.soilMoisture_2}`">{{sensorData.soilMoisture_2}}</div>
                            </div>
                        </div>
                        <div>
                            <div>Status Pumpe</div>
                            <div class="p-4 space-x-6 md:flex">
                                <input type="checkbox" class="toggle" v-model="sensorData.statusPumpe" />
                                {{ sensorData.statusPumpe ? 'ON' : 'OFF' }}
                            </div>
                        </div>
                    </div>
                </div>
                <div>
                    <div class="justify-start text-3xl ">Lufter System</div>
                    <div class="justify-center p-4 space-x-4 text-lg md:flex">
                        <div class="p-4 space-x-6 md:flex">
                            Lufter Status
                        </div>
                        <label class="" for="statusLufter_Low">ECO</label>
                        <div class="p-4 space-x-6 md:flex">
                            <input name="statusLufter_Low" type="checkbox" class="toggle" v-model="sensorData.statusLufter_Low" />
                            {{ sensorData.statusLufter_Low ? 'ON' : 'OFF' }}
                        </div>
                        <label for="statusLufter_Medium">Performance</label>
                        <div class="p-4 space-x-6 md:flex">
                            <input name="statusLufter_High" type="checkbox" class="toggle" v-model="sensorData.statusLufter_High" />
                            {{ sensorData.statusLufter_High ? 'ON' : 'OFF' }}
                        </div>
                    </div>
                </div>
                <div>
                    <div class="justify-start text-3xl ">Lichter System</div>
                    <div class="justify-center p-4 space-x-4 text-lg md:flex">
                        <div class="p-4 space-x-6 md:flex">
                            LED Status
                        </div>
                        <label for="brightness_Led">Led Helligkeit</label>
                        <div class="p-4 space-x-6 md:flex">
                            <input name="brightness_Led" type="range" min="0" max="100" v-model="settingsData.setBrightness" class="range" />
                        </div>
                        <label for="statusLight">Led Status</label>
                        <div class="p-4 space-x-6 md:flex">
                            <input name="statusLight" type="checkbox" class="toggle" v-model="sensorData.statusLight" />
                            {{ sensorData.statusLight ? 'ON' : 'OFF' }}
                        </div>
                        <div class="p-4 space-x-6 md:flex">
                            <label for="getRgbLed">Color Status</label>
                            <input name="getRgbLed" type="color" v-model="sensorData.getRgbLed" class="range" />
                        </div>
                    </div>
                </div>
                <div>
                    <div class="justify-start text-3xl ">EnergieStatus</div>
                    <div class="justify-center p-4 space-x-4 text-lg md:flex">
                        <div>{{ 2.3 }}V</div> <!-- solar_1 -->
                        <div>{{ 3.3 }}V</div> <!-- solar_2 -->
                        <div>{{ 90 }}%</div> <!-- akku -->
                        <div>{{ 11.3 }}V</div> <!-- strom -->
                    </div>

                </div>
                <div>
                    <div class="justify-start text-3xl ">Settings</div>
                    <div class="justify-center p-4 space-x-4 text-lg md:flex">
                        <div>
                            <input type="range" min="0" max="100" :value="80" class="range" /> <!-- brightness -->
                        </div>
                        <div>
                            <input type="range" min="0" max="100" :value="90" class="range" /> <!-- sound -->
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
    <div v-else>
        <div class="flex items-center justify-center space-x-2">
	        <div class="w-4 h-4 rounded-full animate-pulse dark:bg-white-600"></div>
	        <div class="w-4 h-4 rounded-full animate-pulse dark:bg-white-600"></div>
	        <div class="w-4 h-4 rounded-full animate-pulse dark:bg-white-600"></div>
        </div>
    </div>
</template>

<script lang="ts">
export default {
    data() {
        return {
            sensorData: {
                temperature_1: 0,
                humidity_1: 0,
                temperature_2: 0,
                humidity_2: 0,
                soilMoisture_1: 0,
                soilMoisture_2: 0,
                statusPumpe: false,
                statusLufter_Low: false,
                statusLufter_High: false,
                statusLight: false,
                getRgbLed: 'rgb(0,0,0)',
            },
            settingsData: {
                temperature_Min: 0,
                temperature_Avg: 0,
                temperature_Max: 0,
                soilMoisture_Min: 0,
                soilMoisture_Max: 0,
                setBrightness: 0,
                setLufter_Low: false,
                setLufter_High: false,
                setPumpe: false,
                setLight: false,
                setRgbLed: 'rgb(0,0,0)',
                setMatrixLed: 'Text',
            },
            error: [],
        }
    },
    beforeMount() {
        this.fetchData()
    },
    mounted() {
        this.fetchData()
        this.intervalId = setInterval(() => {
            this.fetchData()
        }, 5000)
    },
    unmounted() {
        clearInterval(this.intervalId);
    },
    methods: {
        roundToTwoDecimal(value: number) {
            return Math.round(value * 100) / 100;
        },
        async fetchData() {
            //const runtimeConfig = useRuntimeConfig();
            //const { data: sensorData , error: sensorError } = await useFetch(`${runtimeConfig.public.api_host}/sensor`);
            //const { data: settingsData, error: settingsError } = await useFetch(`${runtimeConfig.public.api_host}/settings`);
            const { data: sensorData, error: sensorError } = await useFetch('/api/sensor');
            const { data: settingsData, error: settingsError } = await useFetch('/api/settings')
            this.sensorData = {
                temperature_1: this.roundToTwoDecimal(sensorData.value.temperature_1),
                humidity_1: this.roundToTwoDecimal(sensorData.value.humidity_1),
                temperature_2: this.roundToTwoDecimal(sensorData.value.temperature_2),
                humidity_2: this.roundToTwoDecimal(sensorData.value.humidity_2),
                soilMoisture_1: sensorData.value.soilMoisture_1,
                soilMoisture_2: sensorData.value.soilMoisture_2,
                statusPumpe: sensorData.value.statusPumpe,
                statusLufter_Low: sensorData.value.statusLufter_Low,
                statusLufter_High: sensorData.value.statusLufter_High,
                statusLight: sensorData.value.statusLight,
                getRgbLed: sensorData.value.getRgbLed,
            };
            this.error = sensorError;
            this.settingsData = settingsData.value;
            this.error = settingsError;
        }
    }
}

</script>

<style scoped></style>

<!--
    <div>
        <div v-if="dataLoaded">
        <div v-for="data in data" :key="data._id">
            <div>{{ data.tempHum.temperature_1 }}</div>
            <div>{{ data.tempHum.humidity_1 }}</div>
            <div>{{ data.tempHum.temperature_2 }}</div>
            <div>{{ data.tempHum.humidity_2 }}</div>
        </div>
    </div>
    <div v-else>
        Loading...
    </div>
    </div>
-->


<!--template>
    <div class="container py-2 md:w-40 bg-clementine-700">
        <div>
            <div class="flex justify-center text-3xl">Devices</div>
            <div class="p-4 text-lg ">
                <div class="flex justify-center p-3 ">{{ devices.esp32[0].connected }}</div>
                <div class="flex justify-center p-3">{{ devices.esp32[0].connected }}</div>
                <div class="flex justify-center p-3">{{ devices.raspberrypi.connected }}</div>
            </div>
        </div>
    </div>
    <div class="container p-2 px-3 bg-minsk-900">
        <div>
            <div class="flex justify-start text-3xl">TempHum</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ tempHum.temperature_1 }}</div>
                <div>{{ tempHum.humidity_1 }}</div>
                <div>{{ tempHum.temperature_2 }}</div>
                <div>{{ tempHum.humidity_2 }}</div>
            </div>
        </div>
        <div>
            <div class="flex justify-start text-3xl">WaterSystem</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ waterSystem.sensor_1 }}</div>
                <div>{{ waterSystem.sensor_2 }}</div>
                <div>{{ waterSystem.pumpe }}</div>
            </div>
        </div>
        <div>
            <div class="flex justify-start text-3xl">LufterLeds</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ lufterLeds.getLufter_1 }}</div>
                <div>{{ lufterLeds.setLufter_Low }}</div>
                <div>{{ lufterLeds.getLufter_2 }}</div>
                <div>{{ lufterLeds.setLufter_High }}</div>
                <div>{{ lufterLeds.getLed }}</div>
                <div>{{ lufterLeds.setLed }}</div>
            </div>    
        </div>
        <div>
            <div class="flex justify-start text-3xl">EnergieStatus</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ energieStatus.solar_1 }}</div>
                <div>{{ energieStatus.solar_2 }}</div>
                <div>{{ energieStatus.akku }}</div>
                <div>{{ energieStatus.strom }}</div>
            </div>
        </div>
        <div>
            <div class="flex justify-start text-3xl">Settings</div>
            <div class="flex justify-center p-4 space-x-4 text-lg">
                <div>{{ settings.brightness }}</div>
                <div>{{ settings.sound }}</div>
            </div>
        </div>
    </div>
</template-->

<!--script setup>
const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
const items = data_items._rawValue.data[0]
const devices = items.devices
const tempHum = items.tempHum
const waterSystem = items.waterSystem
const lufterLeds = items.lufterLeds
const energieStatus = items.energieStatus
const settings = items.settings
console.log(items)
</script-->


<!--script>
export default {
    data() {
        return {
            devices: [],
            tempHum: [],
            waterSystem: [],
            lufterLeds: [],
            energieStatus: [],
            settings: [],
        }
    },
    async mounted() {
        const { data: data_items ,error, refresh, pending } = await useFetch('/api/data')
        const items = data_items._rawValue.data[0]
        this.devices = items.devices
        this.tempHum = items.tempHum
        this.waterSystem = items.waterSystem
        this.lufterLeds = items.lufterLeds
        this.energieStatus = items.energieStatus
        this.settings = items.settings
        console.log(items)
    },
    fetchOnServer: false,
}
</script-->


<!--script>
export default {
    mode: 'client',
    data() {
        return {
            devices: null,
            tempHum: null,
            waterSystem: null,
            lufterLeds: null,
            energieStatus: null,
            settings: null
        }
    },
    async mounted() {
        const { data: data_items } = await this.$fetch('/api/data')
        const items = data_items._rawValue.data[0]
        this.devices = items.devices
        this.tempHum = items.tempHum
        this.waterSystem = items.waterSystem
        this.lufterLeds = items.lufterLeds
        this.energieStatus = items.energieStatus
        this.settings = items.settings
        console.log(this.devices, this.tempHum, this.waterSystem, this.lufterLeds, this.energieStatus, this.settings)
    }
}
</script-->
