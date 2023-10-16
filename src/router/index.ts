import { createRouter, createWebHistory } from 'vue-router'
import homeView from '../components/home.vue'

const router = createRouter({
  history: createWebHistory(import.meta.env.BASE_URL),
  routes: [
    {
      path: '/',
      name: 'home',
      component: homeView
    },

    {
      path: '/manager',
      name: 'manager',
      component: () => import('../components/manager.vue')
    },

    {
      path: '/detail',
      name: 'detail',
      // route level code-splitting
      // this generates a separate chunk (About.[hash].js) for this route
      // which is lazy-loaded when the route is visited.
      component: () => import('../components/manager.vue')
    },
    {
      path: '/addRepository',
      name: 'addRepository',
      component: () => import('../views/addRepository.vue')
    },
    {
      path: '/addItem',
      name: 'addItem',
      component: () => import('../views/addItem.vue')
    },
    {
      path: '/detail',
      name: 'detail',
      component: () => import('../views/detail.vue')
    }
  ]
})

export default router
