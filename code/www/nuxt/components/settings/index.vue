<template>
<div>
    <form @submit.prevent="createForm">
        <div class="grid grid-cols-1 md:grid-cols-2">
            <div>
                <div class="w-full max-w-xs form-control">
                        <label class="label">
                            <span class="label-text">Temperature Minimum</span>
                        </label>
                        <input type="number" placeholder="Type here" class="w-full max-w-xs input input-bordered" v-model="formData.temperature_Min" />
                </div>
                <div class="w-full max-w-xs form-control">
                        <label class="label">
                            <span class="label-text">Temperature Durchschnitt</span>
                        </label>
                        <input type="number" placeholder="Type here" class="w-full max-w-xs input input-bordered" :min="formData.temperature_Min" :max="formData.temperature_Max" v-model="formData.temperature_Avg" />
                </div>
                <div class="w-full max-w-xs form-control">
                        <label class="label">
                            <span class="label-text">Temperature Maximum</span>
                        </label>
                        <input type="number" placeholder="Type here" class="w-full max-w-xs input input-bordered" v-model="formData.temperature_Max" />
                </div>
                <div class="w-full max-w-xs form-control">
                        <label class="label">
                            <span class="label-text">Bodenfeuchtigkeit Minimum</span>
                        </label>
                        <input type="number" placeholder="Type here" class="w-full max-w-xs input input-bordered" v-model="formData.soilMoisture_Min" />
                </div>
                <div class="w-full max-w-xs form-control">
                        <label class="label">
                            <span class="label-text">Bodenfeuchtigkeit Maximum</span>
                        </label>
                        <input type="number" placeholder="Type here" class="w-full max-w-xs input input-bordered" v-model="formData.soilMoisture_Max" />
                </div>
            </div>
            <div>
                <div class="form-control">
                    <label for="setLufter_Low" class="py-3">Lüfter Eco</label>
                    <input type="checkbox" name="setLufter_Low" class="toggle" v-model="formData.setLufter_Low" />
                </div>
                <div class="form-control">
                    <label for="setLufter_Low" class="py-3">Lüfter Performance</label>
                    <input type="checkbox" name="setLufter_High" class="toggle" v-model="formData.setLufter_High" />
                </div>
                <div class="form-control">
                    <label for="setLufter_Low" class="py-3">Pumpe AUS / AN</label>
                    <input type="checkbox" name="setPumpe" class="toggle" v-model="formData.setPumpe" />
                </div>
                <div class="form-control">
                    <label for="setLufter_Low" class="py-3">Licht AUS / AN</label>
                    <input type="checkbox" name="setLight" class="toggle" v-model="formData.setLight" />
                </div>
                <div class="w-full max-w-xs form-control">
                    <label class="label">
                        <span class="label-text">Helligkeit</span>
                    </label>
                    <input type="number" placeholder="Type here" class="w-full max-w-xs input input-bordered" v-model="formData.setBrightness" />
                </div>
                <div class="form-control w-max ">
                    <label for="setRgbLed" class="py-3">Licht Farbe auswählen</label>
                    <input class="flex border-2 min-w-fit border-l-neutral-900" type="color" name="setRgbLed" v-model="formData.setRgbLed" />
                </div>
                <div class="w-full max-w-xs form-control">
                        <label class="label">
                            <span class="label-text">Matrix Led Text einfügen</span>
                        </label>
                        <input type="text" :placeholder="formData.setMatrixLed" class="w-full max-w-xs input input-bordered" name="setMatrixLed" value="" />
                </div>
            </div>
        </div>
        <div class="flex items-center justify-center py-3 md:justify-end">
            <button type="submit" class="btn btn-outline">Save</button>
        </div>
    </form>
</div>
</template>

<script lang="ts" setup>
// https://www.30secondsofcode.org/js/s/rgb-to-hex/
const RGBToHex = (rgbStr: any) => {
    const [r,g,b] = rgbStr.match(/\d+/g).map(Number);
    return '#' + ((r << 16) + (g << 8) + b).toString(16).padStart(6, '0');
};

// https://www.30secondsofcode.org/js/s/hex-to-rgb/
const hexToRGB = (hex: any) => {
    let alpha = false,
        h = hex.slice(hex.startsWith('#') ? 1 : 0);
    if (h.length === 3) h = [...h].map(x => x + x).join('');
    else if (h.length === 8) alpha = true;
    h = parseInt(h, 16);
    return (
        'rgb' +
        (alpha ? 'a' : '') +
        '(' +
        (h >>> (alpha ? 24 : 16)) +
        ', ' +
        ((h & (alpha ? 0x00ff0000 : 0x00ff00)) >>> (alpha ? 16 : 8)) +
        ', ' +
        ((h & (alpha ? 0x0000ff00 : 0x0000ff)) >>> (alpha ? 8 : 0)) +
        (alpha ? `, ${h & 0x000000ff}` : '') +
        ')'
        );
};

//const runtimeConfig = useRuntimeConfig()
let settings_values:any = '';
await get();

let formData = ref({
    temperature_Min: settings_values.temperature_Min || 0,
    temperature_Avg: settings_values.temperature_Avg || 50,
    temperature_Max: settings_values.temperature_Max || 100,
    soilMoisture_Min: settings_values.soilMoisture_Min || 0,
    soilMoisture_Max: settings_values.soilMoisture_Max || 100,
    setLufter_Low: settings_values.setLufter_Low || false,
    setLufter_High: settings_values.setLufter_High || false,
    setPumpe: settings_values.setPumpe || false,
    setLight: settings_values.setLight || false,
    setBrightness: settings_values.setBrightness || 100,
    setRgbLed: settings_values.setRgbLed = RGBToHex(settings_values.setRgbLed) || '#000000',
    setMatrixLed: settings_values.setMatrixLed || '',
})

async function get() {
    //const {data: settings_data, refresh} = await useFetch(`${runtimeConfig.public.api_host}/settings`);
    const { data: settings_data } = await useFetch('/api/settings');
    settings_values = settings_data.value;
}

async function createForm() {
    formData.value.setRgbLed = hexToRGB(formData.value.setRgbLed);
    await update(formData.value);
    await get();
    formData.value.setRgbLed = RGBToHex(settings_values.setRgbLed);
}

async function update(data: any) {
    const res = await $fetch(`${runtimeConfig.public.api_host}/settings`, {
        method: 'PATCH',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    });
    /*
    const res = await useFetch('/api/settings' , {
        method: 'PATCH',
        body: JSON.stringify(data)
    });
    */
}

</script>
