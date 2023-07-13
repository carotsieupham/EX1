// VD1
function createLogger(namespace){
   function logger(message){
      console.log(`[${namespace}] ${message}`)
   }  
   return logger
}
// ===================APP================
// Register.js
const infoLogger = createLogger('Info')
infoLogger('Bắt đàu gửi lại mail')
infoLogger('Gửi mai lỗi lần 1')
infoLogger('Gửi mai lỗi lần 2')
//VD2
function createStorage(key){
   const store = JSON.parse(localStorage.getItem(key)) ?? {}
   const save = ()=>{
      localStorage.setItem(key,JSON.stringify(store))
   }
   const storage={
      get(key){
         return store[key]
      },
      set(key,value){
         store[key]=value
         save()
      },
      remove(){
         delete store[key]
         save()
      }
   }
   return storage
}
// Profile.js
const ProfileSetting=createStorage('profile_setting')
ProfileSetting.set('fullname','Tri')