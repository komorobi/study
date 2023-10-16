import axios from 'axios';
//import EIMessage from 'elemet-plus'
const Service = axios.create({
    baseURL: 'https://uzimg.scutbot.icu',
    headers: {
        "Content-Type": "application/json; charset='UTF-8"
    },

    timeout: 10000
})

//请求拦截器
Service.interceptors.request.use((config) => {
    config.headers.common['Authorization'] = window.sessionStorage.getItem('token')
    return config
})
//响应拦截器
Service.interceptors.response.use((response) => {
    //获取接口返回结果
    return response;


},
    (error: any) => {
        // 处理请求错误
        return Promise.reject(error);
    },
)

export default Service