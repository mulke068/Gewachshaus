<template>
    <div class="main">
        <div class="outer">
            <div class="inner">
                <div id="number">
                    {{ value + unit }}
                </div>
            </div>
        </div>
        <svg width="160px" height="160px">
            <defs>
                <linearGradient id="GradientColor" x2="0%" y2="100%">
                    <stop offset="0%" stop-color="#FF0000" />
                    <stop offset="100%" stop-color="#00FF00" />
                </linearGradient>
            </defs>
            <circle cx="80" cy="80" r="70" stroke-linecap="round" class="progress-ring-circle" :stroke-dasharray="440"
                :stroke-dashoffset="strokeDashoffset" />
        </svg>
    </div>
</template>

<script>
export default {
    mode: "client",
    props: {
        value: Number,
        max: Number,
        min: Number,
        unit: String
    },
    data() {
        return {
            strokeDashoffset: 0
        }
    },
    mounted() {
        this.calculateStrokeDashoffset();
    },
    watch: {
        value: {
            // to update te value of the progress bar
            immediate: true,
            handler(newValue, oldValue) {
                if (newValue !== oldValue) {
                    this.calculateStrokeDashoffset();
                }
            }
        }
    },
    methods: {
        calculateStrokeDashoffset() {
            this.strokeDashoffset = 440 - (440 * (this.value - this.min)) / (this.max - this.min);
        }
    }
}
</script>

<style lang="css" scoped>
.main {
    width: 160px;
    height: 160px;
    position: relative;
}

.outer {
    width: 160px;
    height: 160px;
    padding: 20px;
    box-shadow: 6px 6px 10px -1px rgba(0,0,0,0.15), -6px -6px 10px -1px rgba(255,255,255,0.7);
    border-radius: 50%;
}

.inner {
    width: 120px;
    height: 120px;
    border: 1px solid rgba(255, 255, 255, 0);
    border-radius: 50%;
    box-shadow: inset 4px 4px 6px -1px rgba(0,0,0,0.2),inset
                -4px -4px 6px -1px rgba(255,255,255,0.7),
                -0.5px -0.5px 0px rgba(255,255,255,1),
                0.5px 0.5px 0px rgba(0,0,0,0.15),
                0px 12px 10px -10px rgba(0,0,0,0.05);
}

#number {
    position: absolute;
    top: 50%;
    left: 50%;
    transform: translate(-50%, -50%);
    font-size: 2rem;
    font-weight: 600;
    color: #ffffff;
}

.progress-ring-circle {
    fill: none;
    stroke: url(#GradientColor);
    stroke-width: 20px;
    stroke-linecap: round;
    animation: randani 2s linear forwards;
}

@keyframes randani {
    0% {
        stroke-dashoffset: 440;
    }

    100% {
        stroke-dashoffset: var(strokeDashoffset);
    }
}

svg {
    position: absolute;
    top: 0%;
    left: 0%;
}
</style>


<!--
.outer {
    width: 160px;
    height: 160px;
    padding: 20px;
    box-shadow: 6px 6px 10px -1px rgba(0,0,0,0.15), -6px -6px 10px -1px rgba(255,255,255,0.7);
    border-radius: 50%;
}

.inner {
    width: 120px;
    height: 120px;
    border: 1px solid rgba(255, 255, 255, 0);
    border-radius: 50%;
    box-shadow: inset 4px 4px 6px -1px rgba(0,0,0,0.2),inset
                -4px -4px 6px -1px rgba(255,255,255,0.7),
                -0.5px -0.5px 0px rgba(255,255,255,1),
                0.5px 0.5px 0px rgba(0,0,0,0.15),
                0px 12px 10px -10px rgba(0,0,0,0.05);
}




-->